import cv2
import time
import numpy as np
import math
import HandTrackingModule as htm
#FOR MAC
#import subprocess

#FOR WINDOWS

from comtypes import CLSCTX_ALL
from pycaw.pycaw import AudioUtilities, IAudioEndpointVolume
devices = AudioUtilities.GetSpeakers()
interface = devices.Activate(IAudioEndpointVolume._iid_, CLSCTX_ALL, None)
volume = interface.QueryInterface(IAudioEndpointVolume)
VolRange=volume.GetVolumeRange()

minVol=VolRange[0]
maxVol=VolRange[1]

"""
def set_volume(volume_level):
    try:
        command = f"osascript -e 'set volume output volume {volume_level}'"
        subprocess.run(command, shell=True, check=True)
        print("Volume set to", volume_level)
    except Exception as e:
        print("An error occurred:", e)
def get_volume_range():
    try:
        command = "osascript -e 'get volume settings'"
        output = subprocess.check_output(command, shell=True).decode("utf-8")
        output = output.strip().split(", ")
        volume_range = (int(output[0].split(":")[1]), int(output[1].split(":")[1]))
        return volume_range
    except Exception as e:
        print("An error occurred:", e)
        return None

minVol=0
maxVol=100
"""

w,h=600,400
cap=cv2.VideoCapture(0)
cap.set(3,w)
cap.set(4,h)
pT=0

detector=htm.handDetector(detectionCon=0.9)
volb=400
vol=0
while True:
    success,img=cap.read()
    img=detector.findHands(img)
    lmlist=detector.findPosition(img,draw=False)
    if len(lmlist)!=0:
        x1,y1=lmlist[4][1],lmlist[4][2]
        x2,y2=lmlist[8][1],lmlist[8][2]
        cx,cy=(x1+x2)//2,(y1+y2)//2
        cv2.circle(img,(x1,y1),15,(255,0,255),cv2.FILLED)
        cv2.circle(img, (x2, y2), 15, (255, 0, 255), cv2.FILLED)
        cv2.line(img,(x1,y1),(x2,y2),(255,0,255),3)
        cv2.circle(img, (cx, cy), 15, (255, 0, 255), cv2.FILLED)
        #calculer distance
        length=math.hypot(x2-x1,y2-y1)

        # hand range  50--300
        #Volume range  0---100

        vol=np.interp(length,[50,300],[minVol,maxVol])
        print(int(vol))

           #FOR WINDOWS
        volume.SetMasterVolumeLevel(vol, None)

           # FOR MAC
        #set_volume(vol)

        if length <50:
            cv2.circle(img, (cx, cy), 15, (0, 255, 0), cv2.FILLED)

        volb = np.interp(length, [50, 255], [400, 150])
        cv2.rectangle(img,(50,150),(85,400),(0,255,0),3)
        cv2.rectangle(img, (50, int(volb)), (85, 400), (0, 255, 0), cv2.FILLED)
        cv2.putText(img, f'{int(vol)}%', (40, 450), cv2.FONT_HERSHEY_COMPLEX, 1, (0, 255,255), 2)

    cT=time.time()
    fps=1/(cT-pT)
    pT=cT
    cv2.putText(img,f'FPS {int(fps)}',(10,40),cv2.FONT_HERSHEY_COMPLEX,1,(255,0,0),2)
    cv2.imshow("VOLUME CONTROL",img)
    cv2.waitKey(1)