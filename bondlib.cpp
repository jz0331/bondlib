// bondlib.cpp - test
#include <cassert>
#include "fms_iterable.h"
//#include "tmx_monoid.h"
#include "tmx_math.h"
#include "tmx_date.h"
#include "tmx_variate_normal.h"
#include "tmx_option.h"
#include "tmx_date_business_day.h"
#include "tmx_curve_pwflat.h"
#include "tmx_curve.h"
//#include "tmx_instrument_value.h"
//#include "tmx_value.h"
//#include "tmx_bond.h"
//#include "tmx_bootstrap.h"
//#include "tmx_muni.h"
 
using namespace fms;
using namespace tmx;

#ifdef _DEBUG
//int test_iterable_ptr = iterable::ptr<int>::test();
//int test_iterable_take = iterable::take<iterable::ptr<int>>::test();
//int test_iterable_span = iterable::span<int>::test();
//int test_iterator = iterable::iterator<std::vector<int>::iterator>::test();

//int test_hypergeometric = math::hypergeometric_test();

//int test_monoid_i = monoid_test<int>();
//int test_monoid_d = monoid_test<double>();
//int test_mean_monoid_d = mean_monoid_test<double>();
int test_curve_constant = curve::constant<>::test();
int test_date = date::test();
int test_variate_normal = variate::normal<>::test();
//<<<<<<< main
//int test_black_put = black::put::test();
int test_curve_operator = curve_operator_test();
//int test_pwflat = curve::pwflat_test();
//int test_option_put = option::put::test();
//>>>>>>> main
//int test_date_periodic = date::periodic_test();
//int test_datetime = datetime::test();
//int test_date_dcf = date::dcf::test();
//int test_tmx_monotonic = tmx::monotonic_test();
//int test_pwflat_curve_view = pwflat::view<>::test();
//int test_pwflat_curve_value = pwflat::base<>::test();
//int test_instrument_view = view<>::test();
//int test_instrument_value = value<>::test();
//int test_value_yield_d = value::yield_test<double>();
//int test_value_yield_f = value::yield_test<float>();
//int test_bond_basic = bond::basic_test();
//int test_bootstrap_instrument = bootstrap::instrument_test();
//int test_muni_fit = muni::fit_test();
#endif // _DEBUG

int main()
{
	return 0;
}
