// $Id: tree_base.h,v 1.3 2008/05/22 14:14:19 gdiso Exp $

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



#ifndef __tree_base_h__
#define __tree_base_h__

// C++ includes

// Local includes



// Forward Declarations
class TreeBase;
class MeshBase;
class Point;
class Elem;


namespace Trees
{
  /**
   * \p enum defining how to build the tree.  \p NODES will populate
   * the tree with nodes and then replace the nodes with element
   * connectivity, \p ELEMENTS will populate the tree with the elements
   * directly.
   */
  enum BuildType
  {
    NODES=0,
    ELEMENTS,             // all the element
    ELEMENTS_ON_BOUNDARY, // elements on outside boundary
    SURFACE_ELEMENTS,     // surface element (on boundary or on interface), dim-1
    INVALID_BUILD_TYPE };
}

/**
 * This is the base class for trees, it allows pointer
 * usage of trees.
 */

// ------------------------------------------------------------
// TreeBase class definition
class TreeBase
{
protected:

  /**
   * Constructor.  Protected.
   */
  TreeBase (const MeshBase& m);


public:

  /**
   * Destructor.
   */
  virtual ~TreeBase() {}

  /**
   * Prints the nodes.
   */
  virtual void print_nodes() const = 0;

  /**
   * Prints the nodes.
   */
  virtual void print_elements() const = 0;

  /**
   * @returns the number of active bins.
   */
  virtual unsigned int n_active_bins() const = 0;

  /**
   * @returns a pointer to the element containing point p.
   */
  virtual const Elem* find_element(const Point& p) const = 0;

  /**
   * @return the first element the ray(p,dir) hit
   */
  virtual const Elem * hit_element(const Point & p, const Point & dir) const=0;

  /**
   * @return true if the ray hit the mesh bounding_box
   */
  virtual bool hit_boundbox(const Point & p, const Point & dir) const=0;

  /**
   * @return how many leaf per level
   */
  virtual unsigned int n_leaf() const=0;

protected:

  /**
   * Constant reference to a mesh.  Declared
   * at construction.
   */
  const MeshBase& mesh;

};


// ------------------------------------------------------------
// TreeBase class inline methods

// constructor
inline
TreeBase::TreeBase (const MeshBase& m) :
  mesh(m)
{
}


#endif
