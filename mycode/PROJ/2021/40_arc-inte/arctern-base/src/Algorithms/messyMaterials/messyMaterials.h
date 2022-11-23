/****************************************************************************
 *  Copyright:      Copyright © 2020 intellifusion Inc. All rights Reserved
 *  Description:
 *  author:         chengaohua
 *  Last modified:  2020.08.14
 *  email:          chen.gaohua@intellif.com
 ****************************************************************************/

#ifndef SRC_ALGORITHMS_MESSYMATERIALS_MESSYMATERIALS_H_
#define SRC_ALGORITHMS_MESSYMATERIALS_MESSYMATERIALS_H_
#include <vector>
#include "include/algorithminterface.h"
#include "include/arctern.h"

namespace arctern {

class AlgorithmBase;  ///<

/// \brief 乱堆物料检测
enum MessyMaterialsType {
  MESSY_MATERIALS = 0, ///< 沿街晾挂
};

/// \brief 乱堆物料检测结果
typedef struct {
  ArcternRect rect;      ///< 物体框
  float score;            ///< 可信度
  MessyMaterialsType type;   ///< 物体类型
}MESSY_MATERIALS_DETECT_TINY_INFO;


using DETECT_INFOS = std::vector<MESSY_MATERIALS_DETECT_TINY_INFO>;

/// \brief 垃圾检测运行参数类
class ARCTERN_EXPORT_API MessyMaterialsRunParameter final : public RunParameter {
 public:
  /// \brief 构造函数
  MessyMaterialsRunParameter();

  /// \brief 析构函数
  ~MessyMaterialsRunParameter() final;

  /// \brief 检查函数
  ErrorType CheckSize() const override;
};

/// \brief 垃圾检测结果返回类，存储算法的运行结果
class ARCTERN_EXPORT_API MessyMaterialsResult : public Result {
 public:
  /// \brief 构造函数
  MessyMaterialsResult();

  /// \brief 析构函数
  ~MessyMaterialsResult() override;

  /// \brief 释放资源，内部调用此函数释放资源，上层可以不关注此函数
  void Release() override { detInfos_.clear(); }

  /// \brief 调整容器的大小。上层可以不关注此函数
  /// \param n - 容器尺寸
  void resize(int n) override { detInfos_.resize(n); }

 public:
  std::vector<DETECT_INFOS> detInfos_;   ///<  检测信息
};

/// \brief 垃圾检测算法类
class ARCTERN_EXPORT_API MessyMaterials : public AlgorithmInterface {
 public:
  /// \brief 构造函数
  MessyMaterials();

  /// \brief 析构函数
  ~MessyMaterials() override;

  /// \brief 算法初始化
  /// \param p - 初始化参数
  /// \return 错误码
  ErrorType Init(const InitParameter *p) override;

  /// \brief 释放资源
  void Release() override;

  /// \brief 执行算法
  /// \param p - 运行参数
  /// \return 算法结果
  ErrorType Process(const RunParameter *p,Result *r) override;


 private:
  AlgorithmBase *impl_ = nullptr;    ///< 算法实现类
};
}  /// namespace arctern
#endif  // SRC_ALGORITHMS_MESSYMATERIALS_MESSYMATERIALS_H_