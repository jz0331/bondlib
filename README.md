# BondLib

Bond pricing and analytics

## Datetime

Every analytics library needs to convert a real world date and time
to a floating point number representing time in years and back again. 

A _clock_ has a starting point (or epoch) and a tick rate.
We use the _time point_ [`time_t`](https://en.cppreference.com/w/c/chrono/time_t) for this,
an unsigned integer with epoch midnight January 1, 1970 
[UTC](https://www.ipses.com/eng/in-depth-analysis/standard-of-time-definition/)
with a tick rate of 1 second.

A _duration_ is the difference of clock time points.
the standard library function 
[`difftime`](https://en.cppreference.com/w/c/chrono/difftime)
returns the difference in seconds between two time points as a `double`.
We implement the function `datetime::diffyears` returning the difference
in years by dividing by the number of seconds in a year.
We use the duration `std::chrono::years` to define `datetime::days_per_year`
as the number of days per year. Every day has 86400 = 24 * 60 * 60 seconds
so `datetime::seconds_per_year = 86400 * datetime::days_per_year`.

The function `time_t datetime::add(time_t t, double y)` adds `y` years to `t`.
The invariants are `diffyears(add(t, y), t) == y`
and `add(t0, diffyears(t1, t0) == t1`.

## Date

The type `date::ymd` represents a calendar date with resolution to one day.
Converting a `time_t` to a `date::ymd` depends on the time zone.

## Discount 

Let $f_t$ to be the _(continuously compounded) forward rate_ at time $t$.
The _stochastic discount_ is $D_t = \int_0^t f_s\,ds$.
The _forward curve_ $f(t)$ is defined by $D(t) = E[D_t] = \int_0^t f(s)\,ds$.

The price at $t$ of a zero coupon bond maturing at $u$ is 
$D_t(u) = E_t[D_u]/D_t = E_t[\exp(-\int_t^u f_t(s) ds)]$,
where $f_t(u)$ is the forward curve at time $t$. Note $f(t) = f_0(t)$.

The _forward yield_ at $t$ defined by $D_t(u) = \exp(-(u - t)y_t(u)$.

The implementation uses [piecewise flat](tmx_pwflat.h) forwards.

## Fixed Income

Fixed cash flows $(u_j, c_j)$ where $u_j$ is the time in years
of the $j$th cash flow and $c_j$ is the amount.

## Value

Present value at $t$ is $\sum_{u_j > t} c_j D_t(u_j)$.

Duration at $t$ is the derivative with respect to a parallel shift 
in the forward curve $-\sum_{u_j > t} u_j c_j D_t(u_j)$.

Convexity at $t$ is the second derivative with respect to a parallel shift 
in the forward curve $\sum_{u_j > t} u_j^2 c_j D_t(u_j)$.

Yield is the constant rate that reprices a bond $p(t) = \sum_{u_j > t} c_j \exp(-y(t) (u_j - t))$.

## Bond

A _simple bond_ has indicative data maturity, coupon, frequency (default 2 times per year), and a
day count basis (default 30/360).
The function `tmx::instrument` returns the bond cash flows given the _dated date_.

compounding $(1 + y/n)^n = \exp(f)$

Single call at date and price. Use time-dependent Ho-Lee with constant volatility. 

## Municipal Bond Curve

Municipal bonds are quoted using 5% coupon 10-year non-call par coupons.  
[EMMA](https://emma.msrb.org/ToolsAndResources/ICEYieldCurve?daily=False)
provides daily quotes at maturities for 1 to 30 years.

Bootstrap  

$\Omega$, $\mathcal{A}_t$, $t\in T$, is a partition of $\Omega$, 
$X\colon\mathcal{A}_t\to\bm{R}$ is a measurable function,
$D\colon\mathcal{A}_t\to\bm{R}$ is a measure.

`pairing(X, D, A_t)` is $\int_\Omega X\,dD$

E[max{k - f exp(s X - \kappa(s)), 0}]






