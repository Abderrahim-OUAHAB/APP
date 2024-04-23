## Heart Disease Prediction Project
This project aims to predict the likelihood of heart disease based on various factors. The dataset used for this project is sourced from Kaggle : https://www.kaggle.com/datasets/johnsmith88/heart-disease-dataset .

# Introduction
Heart disease is a significant health concern globally. Predicting the risk of heart disease can aid in early diagnosis and intervention, potentially saving lives. This project utilizes machine learning algorithms to predict the probability of heart disease based on individual characteristics and medical data.

# Libraries Used
-pandas
-seaborn
-scikit-learn
-tkinter (for the GUI)
-PIL (Python Imaging Library)
-joblib
-matplotlib

# Importing the Data
The dataset is imported using pandas' read_csv() function.

# Handling Missing Data
No missing data is found in the dataset.

# Handling Duplicate Data
Duplicate rows are identified and removed from the dataset.

# Exploratory Data Analysis (EDA)
Various visualizations are created to understand the data distribution and relationships between variables. Key visualizations include:

-Count plot of target variable
-Correlation matrix heatmap
-Distribution of categorical variables
-Relationship between chest pain type and target variable
-Relationship between fasting blood sugar and target variable
# Data Processing
-Categorical and numerical columns are separated.
-Categorical columns are one-hot encoded.
-Boolean values are replaced with 1s and 0s.
# Feature Scaling
Numerical features are standardized using scikit-learn's StandardScaler.

# Splitting the Data
The data is split into training and test sets using scikit-learn's train_test_split() function.

# Logistic Regression Model
A logistic regression model is trained on the data, achieving an accuracy of approximately 78.69%.

# Random Forest Classifier Model
A random forest classifier model is trained on the data, achieving an accuracy of approximately 85.25%.

# Model Comparison
A comparison of the logistic regression and random forest classifier models is made based on their accuracies.

# Saving the Model
The trained random forest classifier model is saved using joblib.

# User Interface
A graphical user interface (GUI) is created using tkinter to allow users to input their data and predict the likelihood of heart disease.

# How to Use
1-Clone or download the repository.
2-Ensure all required libraries are installed (pip install -r requirements.txt).
3-Run the GUI application (python gui.py).
4-Enter your details and click on the "Predict" button to see the prediction result.

    Feel free to explore the code and contribute to the project!

### Note: Ensure that the dataset file (heart.csv) is in the same directory as the script files for proper execution.
