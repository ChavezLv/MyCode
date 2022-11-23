//
// Created by Admin on 2019/6/11.
//
#include <UnitTest/UnitTestBase/trt/TrtUtils.h>
#include "TrtGroundTruth.h"
#include "cuda.h"
#include "cuda_runtime.h"

TrtFacePhoneUnittest::TrtFacePhoneUnittest(const TrtTestParam & parameter):
    FacePhoneUnittest(parameter.ymlGroundTruth,parameter.ymlInput,parameter.imgPath,parameter.modelPath,parameter.result),
m_gpuId(parameter.gpuIndex){

}

std::shared_ptr<arctern::AlgorithmInterface> TrtFacePhoneUnittest::createAlgHandle(int batch) {
  std::shared_ptr<arctern::FacePhone> ptr(new arctern::FacePhone);
  arctern::InitParameter initParam;
  initParam.batchNum_ = batch;
  initParam.model_path = modelPath_;

  initParam.gpuId_ = m_gpuId;

  auto ret = ptr->Init(&initParam);

  EXPECT_EQ(ret, arctern::ErrorType::ERR_SUCCESS);

  return ptr;
}

TrtFacePhoneUnittest::~TrtFacePhoneUnittest() {
}


void TrtFacePhoneUnittest::checkPictures(std::shared_ptr<arctern::AlgorithmInterface> alg,
                                                std::shared_ptr<BaseGroundTruthData> gtData,
                                                int startId,
                                                int len) {
  BuildFunc build = std::bind(&TrtFacePhoneUnittest::buildRunParameter,this,gtData,startId,len);
  CheckFunc check = std::bind(&TrtFacePhoneUnittest::checkResult, this,gtData,startId,len,std::placeholders::_1);

  CheckPictures(alg,gtData,startId,len,imgDir_,build,check,result_);
}