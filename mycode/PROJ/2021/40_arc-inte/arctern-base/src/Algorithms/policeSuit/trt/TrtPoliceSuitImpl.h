// ****************************************************************************
// *  Copyright:      Copyright © 2021 intellifusion Inc. All rights Reserved
// *  Description:
// *  author:         kuanghongshen
// *  create:         2021.06.05
// *  email:          kuang.hongshen@intellif.com
// *  modified:
// ****************************************************************************

#ifndef SRC_ALGORITHMS_TRTPOLICESUIT_TRTPOLICESUIT_H_
#define SRC_ALGORITHMS_TRTPOLICESUIT_TRTPOLICESUIT_H_
#include "../../../Base/trt/ArcternAlgorithmEx.h"
#include "../../../Engin/src/trt/trtEngineManager.h"
#include "../../../Processors/NppPreprocessorEx.h"
#include "src/Algorithms/policeSuit/policeSuit.h"
#include "src/common/arcterndefs_config_analyzer.h"
#include "src/common/arcterndefs_generated.h"

namespace arctern {
class TrtPoliceSuitImpl final : public ArcternAlgorithmEx {
public:
  TrtPoliceSuitImpl();
  ~TrtPoliceSuitImpl();

private:
  virtual ArcternRect LocalGetROI(const RunParameter *p, int idx) override;

  virtual void InitPreprocessorRunParam(NppPreprocessorRunPt *runParm) override;

  std::pair<PoliceSuitClassify, float> calcSuit(const float *p_data,
                                                const size_t class_num);
  cv::Rect get_chest_roi(cv::Rect roi, int img_w, int img_h);
  ErrorType LocalPostProcess(const RunParameter *p, int startId, int endId,
                             std::vector<arctern::OutputTensor<float>> &outputs);

  void InitEngines() {}

  ErrorType GetModelsConfigInfo(const MxnetModels *models);
};
} // namespace arctern
#endif