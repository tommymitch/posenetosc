# Posenet to OSC 

This repository contains a modified version of [PoseNet](https://github.com/tensorflow/tfjs-models/tree/master/posenet) by [Dan Oved](https://www.danioved.com/) that sends detected keypoints as OSC encoded datagram packets. This enables tracked keypoints to be used within any OSC compatible environment (Max/MSP, Python, PD, C++, Processing, you name it). This is effectively PoseNet + [osc-js](https://github.com/colinbdclark/osc.js/). 

[PoseNet](https://github.com/tensorflow/tfjs-models/tree/master/posenet) is a wabcam-based real-time motion tracking system that runs in a browser using TensorFlow. 

# Pose Detection in the Browser: PoseNet Model

[Try the demo here!](https://storage.googleapis.com/tfjs-models/demos/posenet/camera.html)

<img src="https://raw.githubusercontent.com/irealva/tfjs-models/master/posenet/demos/camera.gif" alt="cameraDemo" style="width: 600px;"/>

PoseNet can be used to estimate either a single pose or multiple poses, meaning there is a version of the algorithm that can detect only one person in an image/video and one version that can detect multiple persons in an image/video.

[Refer to this blog post](https://medium.com/tensorflow/real-time-human-pose-estimation-in-the-browser-with-tensorflow-js-7dd0bc881cd5) for a high-level description of PoseNet running on Tensorflow.js.

## UPDATES:

This repo is a fork of [tommymitch/posenetosc](https://github.com/tommymitch/posenetosc)

- Upgraded NodeJS to version `19.2.0`
- Switched to using Vite as the build tool, replacing the previous choice of Parcel
- Added `concurrently` to run the app and OSC bridge script together
- Added `@vitejs/plugin-basic-ssl` to enable https and webcam capture over localhost
- Switched to using `pnpm` instead of `yarn`

## Installation

To get this running stand alone on your computer, clone this repo and follow these steps:

- Install node and pnpm
- Install dependencies: `pnpm i`
- Run `pnpm dev`

It will run concurrently `vite` and `node bridge.cjs` (OSC bridge)

In Firefox or Chrome, browse to [https://localhost:1234](https://localhost:1234)


Now keypoints can be received as OSC messages on port 9876.

OSC messages will have an address pattern `/pose/n`, where `n` is the index of the pose (person) found in a frame, and all keypoints for that pose will follow as arguments in the order `part, x, y` where `part` is the keypoint body part (string) and `x` and `y` are the coordinates of the part (floats).

### Keypoints

All keypoints correspond to a body part.  The parts are:

| Part |
| -- |
| nose |
| leftEye |
| rightEye |
| leftEar |
| rightEar |
| leftShoulder |
| rightShoulder |
| leftElbow |
| rightElbow |
| leftWrist |
| rightWrist |
| leftHip |
| rightHip |
| leftKnee |
| rightKnee |
| leftAnkle |
| rightAnkle |
