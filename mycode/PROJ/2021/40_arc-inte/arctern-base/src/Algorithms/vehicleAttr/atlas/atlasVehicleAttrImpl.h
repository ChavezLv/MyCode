//
// Created by lzm on 2021/9/17.
//

#ifndef ARCTERN_BASE_SRC_ATLASLINUXALGORITHMS_VEHICLEATTR_ATLASVEHICLEATTRIMPL_H_
#define ARCTERN_BASE_SRC_ATLASLINUXALGORITHMS_VEHICLEATTR_ATLASVEHICLEATTRIMPL_H_

#include "src/Algorithms/vehicleAttr/vehicleAttr.h"
#include "src/Base/atlas/ArcternAlgorithmEx.h"
namespace arctern {
class AtlasVehicleAttrImpl : public ArcternAlgorithmEx {
 public:
  AtlasVehicleAttrImpl();
  ~AtlasVehicleAttrImpl() override ;
  
 public:
  virtual ErrorType GetModelsConfigInfo(const TrtModels* models) override;


  virtual ErrorType LocalPostProcess(const RunParameter *p, int startId, int endId,
                                      std::vector<std::vector<float>> &outputs) override;

  virtual ErrorType LocalPreProcess(std::vector<DvppDataInfo>& vInputInfo,
                                    std::vector<DvppDataInfo>& vOutputInfos,
                                    std::vector<cv::Rect>& vRects) override;

  virtual cv::Rect LocalGetROI(const RunParameter *p, int idx) override;

  private:
    pair<int, float> CalculateResult(const float *data, int step);
    cv::Rect get_vehicle(const int& width, const int& height, const ArcternRect &bbox);
    std::array<float, 4> m_extScale;
    std::vector<std::string> m_carBrandNames;
};


}

#endif //ARCTERN_BASE_SRC_ATLASLINUXALGORITHMS_VEHICLEATTR_ATLASVEHICLEATTRIMPL_H_