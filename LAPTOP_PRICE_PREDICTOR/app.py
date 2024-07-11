import streamlit as st
import pickle
import numpy as np

# Chargement du modèle et des données
pipe = pickle.load(open('pipe_RF.pkl','rb'))  # Chargement du modèle entraîné
df = pickle.load(open('df.pkl','rb'))  # Chargement du DataFrame utilisé pour l'entraînement

# Configuration de la page Streamlit
st.set_page_config(
    page_title="Laptop Predictor",
    page_icon="💻",
    layout="wide",
    initial_sidebar_state="collapsed",
)

# Définition de l'image de fond et configuration du layout
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

# Titre de l'application
st.title("Laptop Predictor")

# Sidebar pour les options de configuration
with st.sidebar:
    st.markdown("## Options de Configuration")

    # Marque
    company = st.selectbox('Marque', df['Company'].unique())

    # Type d'ordinateur portable
    types = st.selectbox('Type', df['TypeName'].unique())

    # RAM
    ram = st.selectbox('RAM (en Go)', [2, 4, 6, 8, 12, 16, 24, 32, 64])

    # Poids
    weight = st.number_input('Poids de l\'ordinateur portable')

    # Écran tactile
    touchscreen = st.selectbox('Écran tactile', ['Non', 'Oui'])

    # IPS
    ips = st.selectbox('IPS', ['Non', 'Oui'])

    # Taille de l'écran
    screen_size = st.number_input('Taille de l\'écran')

    # Résolution
    resolution = st.selectbox('Résolution de l\'écran', ['1920x1080', '1366x768', '1600x900', '3840x2160', '3200x1800', '2880x1800', '2560x1600', '2560x1440', '2304x1440'])

    # CPU
    cpu = st.selectbox('CPU', df['Cpu brand'].unique())

    # HDD
    hdd = st.selectbox('HDD (en Go)', [0, 128, 256, 512, 1024, 2048])

    # SSD
    ssd = st.selectbox('SSD (en Go)', [0, 8, 128, 256, 512, 1024])

    # GPU
    gpu = st.selectbox('GPU', df['Gpu brand'].unique())

    # Système d'exploitation
    os = st.selectbox('Système d\'exploitation', df['os'].unique())

# Bouton de prédiction
if st.button('Prédire le Prix'):
    # Préparation de la requête
    if touchscreen == 'Oui':
        touchscreen = 1
    else:
        touchscreen = 0

    if ips == 'Oui':
        ips = 1
    else:
        ips = 0

    X_res = int(resolution.split('x')[0])
    Y_res = int(resolution.split('x')[1])
    ppi = ((X_res**2) + (Y_res**2))**0.5 / screen_size

    # Conversion de la requête en tableau numpy
    query = np.array([company, types, ram, weight, touchscreen, ips, ppi, cpu, hdd, ssd, gpu, os])

    # Redimensionnement de la requête pour l'inférence
    query = query.reshape(1, -1)

    # Prédiction
    predicted_price_inr = int(np.exp(pipe.predict(query)[0]))

    # Taux de conversion
    taux_conversion_inr_usd = 0.013  # Taux de conversion exemple : 1 INR = 0.013 USD
    taux_conversion_inr_mad = 0.12   # Taux de conversion exemple : 1 INR = 0.12 MAD

    # Conversion en USD et MAD
    predicted_price_usd = predicted_price_inr * taux_conversion_inr_usd
    predicted_price_mad = predicted_price_inr * taux_conversion_inr_mad

    # Affichage de la prédiction
    st.title(f"{round(predicted_price_usd, 3)} USD\n{round(predicted_price_mad, 3)} MAD")




    
