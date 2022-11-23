//
// Created by Admin on 2019/6/11.
//
#include "AtlasGroundTruth.h"
#include "gtest/gtest.h"
#include "UnitTest/config.h"
#include "include/atlasInit.h"
#if defined(ATLAS_ALLOWED)


TEST(ObjectDet, Atlas001) {
 
 AtlasTestParam parameter;
 parameter.ymlGroundTruth = getDir() + "results_arcterncpp/ARMLINUX_ATLAS/object-det-d-0.0.1-rc-atlas.yml";
 parameter.ymlInput =  "";
 parameter.imgPath = getDir() + "data/atlas/object_det/";
 parameter.modelPath = ARCTERN_PROJECT_PATH + string("/../arctern-models/develop/atlas-models/object-det-b1-acl-atlas300-f16-d-0.0.1.bin");
 parameter.modelPath8 = ARCTERN_PROJECT_PATH + string("/../arctern-models/develop/atlas-models/object-det-b8-acl-atlas300-f16-d-0.0.1.bin");
 parameter.gpuIndex = 0;
 arctern::ObjectDetResult result;
 parameter.result=&result;
 
 auto ret = initAclDeviceEnv(parameter.gpuIndex);
 ASSERT_EQ(ret, true);
 AtlasObjectDetUnittest unittest(parameter);
 unittest.test();
 ret = destroyAclDeviceEnv(parameter.gpuIndex);
 ASSERT_EQ(ret,true);
}


#endif