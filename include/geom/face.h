// $Id: face.h,v 1.2 2008/03/19 13:41:30 gdiso Exp $

// The libMesh Finite Element Library.
// Copyright (C) 2002-2007  Benjamin S. Kirk, John W. Peterson
  
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
  
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
  
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA



#ifndef __face_h__
#define __face_h__

// C++ includes

// Local includes
#include "elem.h"


// Forward declarations
class Mesh;



/**
 * The \p Face is an abstract element type that lives in
 * two dimensions.  A face could be a triangle, a quadrilateral,
 * a pentagon, etc...
 */

// ------------------------------------------------------------
// Face class definition
class Face : public Elem
{
public:

  /**
   * Constructor.  Explicitly specifies the number of
   * nodes and neighbors for which storage will be allocated.
   */
  Face (const unsigned int nn,
	const unsigned int ns,
	Elem* p) :
    Elem(nn, ns, p) {}

  /**
   * @returns 2, the dimensionality of the object.
   */
  unsigned int dim () const { return 2; }

  /**
   * @returns 0.  All 2D elements have no faces, just
   * edges.
   */
  unsigned int n_faces() const { return 0; }

  /**
   * build_side and build_edge are identical for faces
   */
  AutoPtr<Elem> build_edge (const unsigned int i) const
    { return build_side(i); }
  
  /** 
   * in-plane test of a face
   */  
  virtual bool in_plane() const=0;
  
  /** 
   * in-circle test of a face
   */  
  virtual bool in_circle() const=0;
  
  

};

#endif




