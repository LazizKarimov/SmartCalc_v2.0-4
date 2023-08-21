#ifndef CPP3_SMARTCALC_V2_0_2_SRC_SMARTCALC2_0_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_0_2_SRC_SMARTCALC2_0_CONTROLLER_CONTROLLER_H_

#include "../Model/model.h"

namespace s21 {
class Controller {
 public:
  Controller(Model *m);
  ~Controller();

  bool Run(std::string expression, double x);

  double GetCalculationResult();

  void BuildGraphs(std::string expression, double x_begin, double x_end);

  std::vector<double> GetXVectorValues();

  std::vector<double> GetYVectorValues();

  void CleanModel();

 private:
  Model *model_;

  bool ProcessExpression(std::string &expression, double x);
};
}  // namespace s21
#endif  // CPP3_SMARTCALC_V2_0_2_SRC_SMARTCALC2_0_CONTROLLER_CONTROLLER_H_
