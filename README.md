# Posenet to OSC 

This repository contains a modified version of [PoseNet](https://github.com/tensorflow/tfjs-models/tree/master/posenet) by [Dan Oved](https://www.danioved.com/) that sends detected keypoints as OSC encoded datagram packets. This enables tracked keypoints to be used within any OSC compatible environment (Max/MSP, Python, PD, C++, Processing, you name it). This is effectively PoseNet + [osc-js](https://github.com/colinbdclark/osc.js/). 

[PoseNet](https://github.com/tensorflow/tfjs-models/tree/master/posenet) is a wabcam-based real-time motion tracking system that runs in a browser using TensorFlow. 

# Pose Detection in the Browser: PoseNet Model

[Try the demo here!](https://storage.googleapis.com/tfjs-models/demos/posenet/camera.html)

<img src="https://raw.githubusercontent.com/irealva/tfjs-models/master/posenet/demos/camera.gif" alt="cameraDemo" style="width: 600px;"/>

PoseNet can be used to estimate either a single pose or multiple poses, meaning there is a version of the algorithm that can detect only one person in an image/video and one version that can detect multiple persons in an image/video.

[Refer to this blog post](https://medium.com/tensorflow/real-time-human-pose-estimation-in-the-browser-with-tensorflow-js-7dd0bc881cd5) for a high-level description of PoseNet running on Tensorflow.js.

## Installation

To get this running stand alone on your computer, clone this repo and follow these steps:

Install node (using [homebrew](https://brew.sh/)):

```sh
brew install node
```

Install yarn:

```sh
brew install yarn
```

Install dependencies and prepare the build directory:

```sh
yarn
```

Watch files for changes, and launch a dev server:

```sh
yarn watch
``` 

In another terminal window run the bridge node application:

```sh
node bridge.js
``` 

In Firefox or Chrome, browse to [http://localhost:1234](http://localhost:1234)


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
