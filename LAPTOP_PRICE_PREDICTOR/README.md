# Laptop Price Prediction Project

This project aims to predict the price of laptops based on various features such as specifications, hardware components, and operating systems. The project includes data preprocessing, exploratory data analysis (EDA), feature engineering, and model building using machine learning techniques.

## Project Structure

The project is organized into the following sections:

1. **Data Cleaning**: 
   - Removed unnecessary columns.
   - Cleaned and converted columns to appropriate data types.
   - Extracted and processed relevant features.

2. **Exploratory Data Analysis (EDA)**:
   - Analyzed distributions, relationships, and patterns in the data using various plots.
   - Explored relationships between features and the target variable ('Price').
   - Created new features based on existing ones.

3. **Feature Engineering**:
   - Engineered new features like 'os', 'HDD', 'SSD', etc.
   - Transformed categorical variables into numerical representations.

4. **Model Building**:
   - Trained multiple regression models including Linear Regression, K-Nearest Neighbors (KNN), Support Vector Machine (SVM), Decision Tree, Random Forest, and Gradient Boosting.
   - Evaluated models using R-squared score and Mean Absolute Error (MAE).
   - Identified Random Forest as the best-performing model based on evaluation metrics.

5. **Model Evaluation and Selection**:
   - Compared the performance of different models using a bar plot.
   - Selected Random Forest as the final model due to its high accuracy and low MAE.

6. **Model Saving**:
   - Saved the final model (`pipe_RF`) and the preprocessed dataframe (`df`) using pickle.

## Files in the Repository

- `laptop.csv`: The dataset containing information about laptops.
- `laptop_price_prediction.ipynb`: Jupyter Notebook containing the Python code for data preprocessing, EDA, feature engineering, and model building.
- `README.md`: This file providing an overview of the project.

## Usage

To run the project:

1. Ensure you have all the necessary libraries installed (NumPy, Pandas, Matplotlib, Seaborn, Scikit-learn).
2. Clone the repository to your local machine.
3. Open and run the Jupyter Notebook (`laptop_price_prediction.ipynb`) in your Python environment.
4. Follow the instructions in the notebook to execute each section of the project.

## Dependencies

- Python 3
- NumPy
- Pandas
- Matplotlib
- Seaborn
- Scikit-learn

## License

This project is licensed under the MIT License. See the [LICENSE](https://github.com/Abderrahim-OUAHAB/MY-PROJECT/blob/main/LICENSE) file for details.

### NB
to run the app tap in terminal or cmd : streamlit run app.py
