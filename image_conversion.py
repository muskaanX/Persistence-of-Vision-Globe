from PIL import Image

# Loading the image
image_path = "globe_pov.jpg"
image = Image.open(image_path)

# Obtaining the dimensions of the image
original_width, original_height = image.size

# Defining the desired height as 64 because we have 64 LEDs (feel free to modify as required)
resize_height = 64

# Calculating the dimensions for splitting
split_width = original_width // 2

# Splitting the image into left and right parts
left_image = image.crop((0, 0, split_width, original_height))
right_image = image.crop((split_width, 0, original_width, original_height))

# Resizing the left part while maintaining the aspect ratio
left_aspect_ratio = split_width / original_height
left_resize_width = int(left_aspect_ratio * resize_height)
left_image_resized = left_image.resize((left_resize_width, resize_height))

# Resizing the right part while maintaining the aspect ratio
right_aspect_ratio = (original_width - split_width) / original_height
right_resize_width = int(right_aspect_ratio * resize_height)
right_image_resized = right_image.resize((right_resize_width, resize_height))

# Saving the resized images
left_image_resized.save("left_image.jpg")
right_image_resized.save("right_image.jpg")

# If Needed: Displaying the resized images
# left_image_resized.show()
# right_image_resized.show()
