/*=========================================================================

  Program:   Visualization Toolkit
  Module:    vtkOTScatterPlotMatrix.h

  Copyright (c) Ken Martin, Will Schroeder, Bill Lorensen
  All rights reserved.
  See Copyright.txt or http://www.kitware.com/Copyright.htm for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/

/**
 * @class   vtkOTScatterPlotMatrix
 * @brief   container for a matrix of charts.
 *
 *
 * This class specialize vtkScatterPlotMatrix by adding a density map
 * on the chart, computed with OpenTURNS
 *
 * @sa
 * vtkScatterPlotMatrix vtkOTDensityMap
*/

#ifndef vtkOTScatterPlotMatrix_h
#define vtkOTScatterPlotMatrix_h

#include "vtkScatterPlotMatrix.h"

class VTKCHARTSCORE_EXPORT vtkOTScatterPlotMatrix : public vtkScatterPlotMatrix
{
public:
  vtkTypeMacro(vtkOTScatterPlotMatrix, vtkScatterPlotMatrix);
  void PrintSelf(ostream& os, vtkIndent indent) VTK_OVERRIDE;

  /**
   * Creates a new object.
   */
  static vtkOTScatterPlotMatrix* New();

  /**
   * Set the visibility of density map for the specifid plotType, false by default
   */
  void SetDensityMapVisibility(int plotType, bool visible);

  /**
   * Set the density line size for the specified plotType, 2 by default
   */
  void SetDensityLineSize(int plotType, float size);

  /**
   * Set the color for the specified plotType, automatically distributed on HSV by default
   */
  void SetDensityMapColor(int plotType, unsigned int densityLineIndex, const vtkColor4ub& color);

protected:
  vtkOTScatterPlotMatrix();
  ~vtkOTScatterPlotMatrix() VTK_OVERRIDE;

  /**
   * Add a density map as a supplementary plot,
   * with provided row and column, computed with OpenTurns
   * if DensityMapVisibility is true and we are not animating
   */
  virtual void AddSupplementaryPlot(vtkChart* chart,
    int plotType,
    vtkStdString row,
    vtkStdString column,
    int plotCorner = 0) VTK_OVERRIDE;

private:
  vtkOTScatterPlotMatrix(const vtkOTScatterPlotMatrix&) VTK_DELETE_FUNCTION;
  void operator=(const vtkOTScatterPlotMatrix&) VTK_DELETE_FUNCTION;

  class DensityMapSettings;
  std::map<int, DensityMapSettings*> DensityMapsSettings;
};

#endif // vtkOTScatterPlotMatrix_h
