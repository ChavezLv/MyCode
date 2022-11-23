//
// Created by Admin on 2019/6/11.
//
#include "AtlasGroundTruth.h"

AtlasFaceQualityUnittest::AtlasFaceQualityUnittest(const AtlasTestParam & parameter):
FaceQualityUnittest(parameter.ymlGroundTruth,parameter.ymlInput,parameter.imgPath,parameter.modelPath,parameter.result),
m_gpuId(parameter.gpuIndex),m_modelsPath8(parameter.modelPath8){

}

std::shared_ptr<arctern::AlgorithmInterface> AtlasFaceQualityUnittest::createAlgHandle(int batch) {
  std::shared_ptr<arctern::FaceQuality> ptr(new arctern::FaceQuality);
  arctern::InitParameter initParam;
  initParam.batchNum_ = batch;
  if(initParam.batchNum_ == 8){
    initParam.model_path = m_modelsPath8;
  }
  else{
    initParam.model_path = modelPath_;
  }
  
  initParam.gpuId_ = m_gpuId;

  auto ret = ptr->Init(&initParam);

  EXPECT_EQ(ret, arctern::ErrorType::ERR_SUCCESS);

  return ptr;
}

AtlasFaceQualityUnittest::~AtlasFaceQualityUnittest() {
}


void AtlasFaceQualityUnittest::checkPictures(std::shared_ptr<arctern::AlgorithmInterface> alg,
                                                std::shared_ptr<BaseGroundTruthData> gtData,
                                                int startId,
                                                int len) {
  BuildFunc build = std::bind(&AtlasFaceQualityUnittest::buildRunParameter,this,gtData,startId,len);
  CheckFunc check = std::bind(&AtlasFaceQualityUnittest::checkResult, this,gtData,startId,len,std::placeholders::_1);

  CheckPictures(alg,gtData,startId,len,imgDir_,build,check,result_);
}