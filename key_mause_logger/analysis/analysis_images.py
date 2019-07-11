import cv2
import pandas as pd
import numpy as np
from os import listdir
from os.path import isfile, join

path_screen = "../data/screenshots/"
path_table = "../data/csv_data_keylogger.csv"
path_processing = "../data/processed_images/"
onlyfiles = [f for f in listdir(path_screen) if isfile(join(path_screen, f))]

font = cv2.FONT_HERSHEY_SIMPLEX
points = pd.read_csv(path_table, sep=",", encoding="utf8", errors='ignore')
points['key_code'] = points['key_code'].dropna()
points['timing_ms'] = points['timing_ms'].dropna()
points['absolut_ms'] = points['absolut_ms'].dropna()
points = points.loc[points['key_code'] != "key_code"]
for i in range(len(points)):
    points.iloc[i,1] = int(points.iloc[i,1])
for i in range(len(points)):
    points.iloc[i,2] = int(points.iloc[i,2])
points['absolut_ms'] = points['absolut_ms'] - min(points['absolut_ms'])

drop_index = []
for j in range(len(points)):
    if (int(points.iloc[j,0]!='RBUTTON') & int(points.iloc[j,0]!='MBUTTON') & int(points.iloc[j,0]!='LBUTTON')):
        drop_index.append(j)
points = points.drop(points.index[drop_index])

i = -1
for f in onlyfiles:
    im = cv2.imread(path_screen+f, cv2.IMREAD_COLOR)
    cv2.imshow('image',im)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    i += 1
    if points.iloc[i,0]=='RBUTTON':
        cv2.circle(im,(int(points.iloc[i,3]),int(points.iloc[i,4])),10,(0,0,255),-1, 4)
        cv2.putText(im,"timing: "+str(points.iloc[i,1])+" absol: "+str(points.iloc[i,2]),(int(points.iloc[i,3])-50,int(points.iloc[i,4])-30),font,.7,(0,0,255),2,cv2.LINE_AA)
    if points.iloc[i,0]=='LBUTTON':
        cv2.circle(im,(int(points.iloc[i,3]),int(points.iloc[i,4])),7,(0,255,0),-1, 4)
        cv2.putText(im,"timing: "+str(points.iloc[i,1])+" absol: "+str(points.iloc[i,2]),(int(points.iloc[i,3])-50,int(points.iloc[i,4])+30),font,.7,(0,255,0),2,cv2.LINE_AA)
    cv2.imshow('image', im)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    cv2.imwrite(path_processing + f, im)
