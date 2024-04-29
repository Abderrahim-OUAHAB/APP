import streamlit as st
import pickle
import numpy as np

# import the model
pipe = pickle.load(open('pipe_RF.pkl','rb'))
df = pickle.load(open('df.pkl','rb'))

# Set page configuration
st.set_page_config(
    page_title="Laptop Predictor",
    page_icon="💻",
    layout="wide",
    initial_sidebar_state="collapsed",
)

# Define background image and set layout
st.markdown(
    """
    <style>
    .reportview-container {
        background: url("pic.jpeg");
        background-size: cover;
    }
    </style>
    """,
    unsafe_allow_html=True
)

st.title("Laptop Predictor")

# Sidebar
with st.sidebar:
    st.markdown("## Configuration Options")

    # Brand
    company = st.selectbox('Brand', df['Company'].unique())

    # Type of laptop
    types = st.selectbox('Type', df['TypeName'].unique())

    # RAM
    ram = st.selectbox('RAM (in GB)', [2, 4, 6, 8, 12, 16, 24, 32, 64])

    # Weight
    weight = st.number_input('Weight of the Laptop')

    # Touchscreen
    touchscreen = st.selectbox('Touchscreen', ['No', 'Yes'])

    # IPS
    ips = st.selectbox('IPS', ['No', 'Yes'])

    # Screen size
    screen_size = st.number_input('Screen Size')

    # Resolution
    resolution = st.selectbox('Screen Resolution', ['1920x1080', '1366x768', '1600x900', '3840x2160', '3200x1800', '2880x1800', '2560x1600', '2560x1440', '2304x1440'])

    # CPU
    cpu = st.selectbox('CPU', df['Cpu brand'].unique())

    # HDD
    hdd = st.selectbox('HDD (in GB)', [0, 128, 256, 512, 1024, 2048])

    # SSD
    ssd = st.selectbox('SSD (in GB)', [0, 8, 128, 256, 512, 1024])

    # GPU
    gpu = st.selectbox('GPU', df['Gpu brand'].unique())

    # OS
    os = st.selectbox('OS', df['os'].unique())

# Prediction button
if st.button('Predict Price'):
    # Prepare query
    if touchscreen == 'Yes':
        touchscreen = 1
    else:
        touchscreen = 0

    if ips == 'Yes':
        ips = 1
    else:
        ips = 0

    X_res = int(resolution.split('x')[0])
    Y_res = int(resolution.split('x')[1])
    ppi = ((X_res**2) + (Y_res**2))**0.5 / screen_size
    query = np.array([company, types, ram, weight, touchscreen, ips, ppi, cpu, hdd, ssd, gpu, os])

    query = query.reshape(1, 12)

    # Perform prediction
    predicted_price_inr = int(np.exp(pipe.predict(query)[0]))
    
    # Conversion rates
    exchange_rate_inr_to_usd = 0.013  # Example exchange rate: 1 INR = 0.013 USD
    exchange_rate_inr_to_mad = 0.12   # Example exchange rate: 1 INR = 0.12 MAD

    # Convert to USD and MAD
    predicted_price_usd = predicted_price_inr * exchange_rate_inr_to_usd
    predicted_price_mad = predicted_price_inr * exchange_rate_inr_to_mad

    # Display prediction
    st.title(f"{round(predicted_price_usd,3)} USD\n{round(predicted_price_mad,3)} MAD")




    
