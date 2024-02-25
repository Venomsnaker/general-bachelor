img_path = 'D:\Projects\general-bachelor\term-4th\IMG_20231014_173306.jpg'
img = image.load_img(img_path, target_size=img_size)
img_array = image.img_to_array(img)
img_array = np.expand_dims(img_array, axis=0)
img_array = scalar(img_array)
predictions = model.predict(img_array)
predicted_class = np.argmax(predictions, axis=1)
print("Predicted class:", class_labels[int(predicted_class)])