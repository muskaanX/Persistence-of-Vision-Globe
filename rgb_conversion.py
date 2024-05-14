from PIL import Image
import pandas as pd

# Function to extract RGB values and save to CSV
def save_rgb_to_csv(image_path, csv_path):

    image = Image.open(image_path)
    image = image.convert("RGB") # For RGB conversion

    width, height = image.size # Obtaining image dimensions
    data = [] # Initializing a list to hold the RGB values

    for y in range(height):  # Looping through each pixel in the image
        row = []
        for x in range(width):
            r, g, b = image.getpixel((x, y))
            row.append((r, g, b))
        data.append(row)

    df = pd.DataFrame(data) # Converting the list to a DataFrame
    df.to_csv(csv_path, index=False, header=False) # Saving the DataFrame to a CSV file

# Paths to the images to be loaded for conversion
image_path_left = "left_image.jpg"
image_path_right = "right_image.jpg"

# Paths to save the CSV files with the converted RGB information
csv_path_left = "left_image_rgb.csv"
csv_path_right = "right_image_rgb.csv"

# Saving RGB values of each image to separate CSV files
save_rgb_to_csv(image_path_left, csv_path_left)
save_rgb_to_csv(image_path_right, csv_path_right)

csv_path_left, csv_path_right
