/*
 * (C) Copyright 2019-2020 UCAR
 *
 * This software is licensed under the terms of the Apache Licence Version 2.0
 * which can be obtained at http://www.apache.org/licenses/LICENSE-2.0.
 */

#ifndef UCLDASV2_GEOMETRY_GEOMETRY_H_
#define UCLDASV2_GEOMETRY_GEOMETRY_H_

#include <ostream>
#include <string>
#include <vector>

#include "eckit/mpi/Comm.h"

#include "oops/util/ObjectCounter.h"
#include "oops/util/Printable.h"

// forward declarations
namespace eckit {
  class Configuration;
}
namespace ucldasv2 {
  class GeometryIterator;
}

// ----------------------------------------------------------------------------

namespace ucldasv2 {

  // Geometry class
  class Geometry : public util::Printable,
                   private util::ObjectCounter<Geometry> {
   public:
    static const std::string classname() {return "ucldasv2::Geometry";}

    // constructors and destructor
    explicit Geometry(const eckit::Configuration &, const eckit::mpi::Comm &);
    Geometry(const Geometry &);
    ~Geometry();

    // accessors
    const eckit::mpi::Comm & getComm() const {return comm_;}

    // These are needed for the GeometryIterator Interface
    // TODO(template_impl) GeometryIterator begin() const; 
    // TODO(template_impl) GeometryIterator end() const; 

    // vertical coordinate (only needed for GETKF?)
    std::vector<double> verticalCoord(std::string &) const;

   private:
    void print(std::ostream &) const;

    const eckit::mpi::Comm & comm_;
  };
}  // namespace ucldasv2

#endif  // UCLDASV2_GEOMETRY_GEOMETRY_H_