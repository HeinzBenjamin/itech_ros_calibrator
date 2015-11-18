# itech_ros_calibrator
Let's you apply ROS camera calibration from custom .yaml or .ini files to your camera topic

#### INSTALLATION

```
cd catkin_ws/src
git clone https://github.com/HeinzBenjamin/itech_ros_calibrator
cd ..
catkin_make itech_ros_calibrator
cd src/itech_ros_calibrator/src
g++ apply_camera_info.cpp -o apply_camera_info -I/opt/ros/indigo/include -L/opt/ros/indigo/lib -Wl,-rpath,/opt/ros/indigo/lib -lroscpp -lrosconsole -lrostime -lroscpp_serialization -lcamera_calibration_parsers
cd ../../..
source devel/setup.bash
```
-----

#### USAGE

```
rosrun itech_ros_calibrator apply_camera_info <camera topic> <calibration_file_name>
```
-----

#### EXAMPLE

```
rosrun itech_ros_calibrator apply_camera_info /camera ~/.ros/camera_info/calibration_file.yaml
```

#### ADDITIONAL NOTES
```
when supplying the camera topic, always make sure, it ends with a '/' (e.g. '/camera/' when using ueye_cam or simply '/' when using ueye)
when messages are being remapped via launch files (for example in some launch files of ueye), always make sure to supply the ORIGINAL <camera topic> and NOT the remapped <camera topic>

Have fun
Ben
```
