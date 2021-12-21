/*
 * (C) Copyright 2019-2021 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#ifndef UCLDASV2_GETVALUES_GETVALUES_H_
#define UCLDASV2_GETVALUES_GETVALUES_H_

#include <memory>
#include <ostream>
#include <string>

#include "ucldasv2/Fortran.h"

#include "oops/util/ObjectCounter.h"
#include "oops/util/Printable.h"

#include "ufo/Locations.h"

// Forward declarations
namespace oops {
  class Variables;
}

namespace ufo {
  class GeoVaLs;
}
namespace ucldasv2 {
  class Geometry;
  class State;
}

//-----------------------------------------------------------------------------

namespace ucldasv2 {

  /// UCLDASV2 GetValues
  /*!
   * GetValues: interpolate State to observation locations
   */
class GetValues : public util::Printable,
                    private util::ObjectCounter<GetValues> {
 public:
  static const std::string classname() {return "ucldasv2::GetValues";}

/// saves all locations locs to use during filling GeoVaLs
  GetValues(const Geometry &, const ufo::Locations & locs,
            const eckit::Configuration & config);
  virtual ~GetValues();

  /// fills in geovals for all observations in the timeframe (t1, t2],
  /// geovals are interpolated trilinearly from state at the nearest gridpoints
  void fillGeoVaLs(const State &,
                   const util::DateTime & t1,
                   const util::DateTime & t2,
                   ufo::GeoVaLs &) const;

 private:
  void print(std::ostream &) const;
  F90getval keyGetValues_;
  ufo::Locations locs_;
  std::shared_ptr<const Geometry> geom_;
};
// -----------------------------------------------------------------------------

}  // namespace ucldasv2

#endif  // UCLDASV2_GETVALUES_GETVALUES_H_
