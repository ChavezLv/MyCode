//
// Created by Admin on 2021/6/18.
//

#include "TrtGroundTruth.h"
#include "gtest/gtest.h"
#include "UnitTest/config.h"

#if defined(TRT_ALLOWED)

TEST(FaceJoy, TRT160) {

  TrtTestParam parameter;
  parameter.ymlGroundTruth = getDir() + "results_arcterncpp/LINUX_MXNET_CPU/face-joy-1.6.0-rc.yml";
  parameter.ymlInput = getDir() + "input_params/face-joy-1.6.0-i.yml";
  parameter.imgPath = getDir() + "/data/predict_face_joy/";
  parameter.modelPath = ARCTERN_PROJECT_PATH + string("/../arctern-models/develop/face/face-joy-1.6.0.bin");
  parameter.irModelPath = "trt_mid_model_file.test";
  parameter.gpuIndex = 0;
  arctern::FaceJoyResult result;
  parameter.result=&result;
  TrtFaceJoyUnittest unittest(parameter);
  unittest.test();
}


#endif