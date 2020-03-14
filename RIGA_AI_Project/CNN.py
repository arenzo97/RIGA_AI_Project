from __future__ import absolute_import, division, print_function, unicode_literals

import tensorflow as tf
import glob
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np

from tensorflow.keras import datasets, layers, models
from sklearn.svm import SVC
from sklearn.ensemble import RandomForestClassifier
from PIL import Image
from sklearn.model_selection import StratifiedKFold
from datetime import datetime

def converttostr(input_seq):
    # Join all the strings in list
    res = ''
    for x in input_seq:
        res = res + str(x) + ' ' 
    return res

#CNN Code
def RunCNN(train_images,test_images,train_labels,test_labels):
    model = models.Sequential()
    
    model.add(layers.Conv2D(32, (3, 3), activation='relu', input_shape=(240, 320, 3)))
    model.add(layers.MaxPooling2D((2, 2)))
    #Here!
    #model.add(tf.keras.layers.Dropout(0.3))
    
    model.add(layers.Conv2D(64, (3, 3), activation='relu'))
    model.add(layers.MaxPooling2D((2, 2)))
    #Here!
    #model.add(tf.keras.layers.Dropout(0.3))
    
    model.add(layers.Conv2D(64, (3, 3), activation='relu'))

    #model.summary() 

    model.add(layers.Flatten())
    model.add(layers.Dense(64, activation='relu'))
    model.add(layers.Dense(10, activation='softmax'))

    model.summary()

    model.compile(optimizer='adam',
              loss='sparse_categorical_crossentropy',
              metrics=['accuracy'])

    history = model.fit(train_images, train_labels, epochs=10,
                    validation_data=(test_images, test_labels))

#plt.plot(history.history['accuracy'], label='accuracy')
#plt.plot(history.history['val_accuracy'], label='val_accuracy')
#plt.xlabel('Epoch')
#plt.ylabel('Accuracy')
#plt.ylim([0.5, 1])
#plt.legend(loc='lower right')

    test_loss, test_acc = model.evaluate(test_images, test_labels, verbose=2)

    print(test_acc);
    return(test_acc);

#Images are 960,1280
#Resize to 240,320

#Code starts here...

now = datetime.now()
current_time = now.strftime("%H:%M:%S")
print("Current Time =", current_time)
file_object = open('/home/phi/Steve/x.txt', 'a')
file_object.write('10 No Dropout\n')

print(tf.__version__)
print('Hello')

#path = "Z:\\Data\\Collaborations\\Juliana\\Picture Cancer Cell\\AllData v2\\*.jpg"
path = "/home/phi/Juliana/AllData v2/*.jpg"

x = []
y = []
for filename in glob.glob(path):
    x.append(filename)
    # im = mpimg.imread(filename)
    #im = Image.open(filename).convert('L')
    #im = Image.open(filename)
    #y.append(np.array(im))
    #print(filename + " : " + np.array(im).shape.__str__())
list.sort(x)
print(x)
for fn in x:
    im = Image.open(fn)
    im = im.resize((320,240),Image.ANTIALIAS)
    y.append(np.array(im))
    print(fn + " : " + np.array(im).shape.__str__())
#exit(1)

lds = np.ndarray(shape=(len(y), 240, 320,3))
for i in range(len(y)):
    lds[i, :, :] = y[i]

# im = mpimg.imread(x[0])
#im = y[0]
#plt.imshow(im)
#print(im.shape)
im2 = im.resize((500,400),Image.ANTIALIAS)
#plt.imshow(im2)
#exit(1)

# TensorFlow and tf.keras
import tensorflow as tf
from tensorflow import keras

# Helper libraries
import numpy as np
import matplotlib.pyplot as plt

print(tf.__version__)

fashion_mnist = keras.datasets.fashion_mnist

(train_images, train_labels), (test_images, test_labels) = fashion_mnist.load_data()

class_names = ['M1', 'M2', 'M3', 'M5',]

ti = train_images[0]
print(ti.shape)

#im = im / 255.0
#ti = ti / 255.0

print("test")

train_images = lds
test_images = lds

train_images = train_images / 255.0

test_images = test_images / 255.0

c1 = [1] * 70
c2 = [2] * 126
c3 = [3] * 91
c4 = [5] * 25

z = c1
z.extend(c2)
z.extend(c3)
z.extend(c4)

print(len(y))

#exit(1)

train_labels = z
test_labels = z

#Insert KFold code - train_images and train_labels into 10 folds
for i in range(1,11):
    acc = [];
    #Here! 5 or 10 folds
    skf = StratifiedKFold(n_splits=5)
    
    skf.get_n_splits(train_images,train_labels)
    for train_index, test_index in skf.split(train_images,train_labels):
        train_d = train_images[train_index];
        #train_c = train_labels[train_index];
        train_c = [train_labels[j] for j in train_index];
        test_d = train_images[test_index];
        #test_c = train_labels[test_index];
        test_c = [train_labels[j] for j in test_index];
        print("TRAIN:", len(train_index), "TEST:", len(test_index))
        print("Train:",train_c)
        print("Test:",test_c)
        a = RunCNN(train_d,test_d,train_c,test_c)
        acc.append(a)

    print(acc);
    file_object.write(converttostr(acc))
    file_object.write('\n')
    print(sum(acc) / len(acc));

    now = datetime.now()
    current_time = now.strftime("%H:%M:%S")
    print("Current Time =", current_time)

file_object.close()