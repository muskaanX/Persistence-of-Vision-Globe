import csv

def convert_to_crgb_array(csv_filename):
    with open(csv_filename, 'r') as file:
        csv_reader = csv.reader(file)
        all_rows = list(csv_reader)  # Read all data

    output = "CRGB image_data[360][64] = {\n"
    for row in all_rows:
        output += "{"
        for color in row:
            r = (int(color) >> 16) & 0xFF
            g = (int(color) >> 8) & 0xFF
            b = int(color) & 0xFF
            output += f"CRGB(0x{r:02X}, 0x{g:02X}, 0x{b:02X}), "
        output = output[:-2] + "},\n"  # Remove last comma and add row end
    output += "};"
    
    with open('image_rgb_data.txt', 'w') as out_file:
        out_file.write(output)  # Write to an output file

# Replace 'your_data.csv' with the path to your CSV file
convert_to_crgb_array('image_data.csv')
