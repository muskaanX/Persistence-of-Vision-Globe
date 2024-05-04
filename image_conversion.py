from PIL import Image
import numpy as np

def prepare_image(image_path, output_width, output_height):
  img = Image.open(image_path)
  img = img.resize((output_width, output_height))
  img = img.convert('RGB')

  data = []
  for i in range(img.height):
    row = []
    for j in range(img.width):
      pixel = img.getpixel((j, i))
      color = (pixel[0] << 16) + (pixel[1] << 8) + pixel[2]
      row.append(color)
    data.append(row)
  return np.array(data)

image_data = prepare_image('globe_pov.jpg', 360, 64)  # 360 degrees and 64 LEDs per side
np.savetxt('image_data.csv', image_data, delimiter=',', fmt='%d') # save data as csv to be read further
