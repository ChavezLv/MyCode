//
// Created by Admin on 2021/6/18.
//

#ifndef ARCTERN_BASE_SRC_ALGORITHMS_PERSONSCARF_TRT_TRTPERSONSCARFIMPL_H_
#define ARCTERN_BASE_SRC_ALGORITHMS_PERSONSCARF_TRT_TRTPERSONSCARFIMPL_H_
#include "src/common/arcterndefs_generated.h"
#include "src/common/arcterndefs_config_analyzer.h"
#include "src/common/tensor.h"
#include "src/common/imageConvert.h"
#include "src/common/trt/TrtAlgorithmUtil.h"

#include "src/Base/trt/ArcternAlgorithmEx.h"
#include "../../../Processors/NppPreprocessorEx.h"
#include "src/common/testUtil.h"
#include "src/Algorithms/personScarf/personScarf.h"

using namespace std;
namespace arctern{
class TrtPersonScarfImpl: public ArcternAlgorithmEx{
 public:
  TrtPersonScarfImpl();

  virtual ~TrtPersonScarfImpl();



  virtual void InitPreprocessorRunParam(NppPreprocessorRunPt *runParm) override;

  virtual ErrorType GetModelsConfigInfo(const MxnetModels *models) override;

  virtual ErrorType LocalPostProcess(const RunParameter *p, int startId,
                                     int endId,vector<arctern::OutputTensor<float>> &outputs) override;

  virtual ArcternRect LocalGetROI(const RunParameter *p, int idx) override;

 private:
  pair<int,float> CalculateResult(const float *data, int step);
  ArcternRect CheckRect(const int width, const int height,
                        const ArcternRect bbox);
 protected:
  std::array<float, 4> m_extScale;
};
}
#endif //ARCTERN_BASE_SRC_ALGORITHMS_PERSONSCARF_TRT_TRTPERSONSCARFIMPL_H_