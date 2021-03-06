/* -*-c++-*- */
/* osgEarth - Dynamic map generation toolkit for OpenSceneGraph
 * Copyright 2016 Pelican Mapping
 * http://osgearth.org
 *
 * osgEarth is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>
 */
#include <osgEarthFeatures/CentroidFilter>
#include <osgEarthFeatures/FilterContext>

#define LC "[CentroidFilter] "

using namespace osgEarth;
using namespace osgEarth::Features;

//------------------------------------------------------------------------

CentroidFilter::CentroidFilter()
{
    //NOP
}

FilterContext
CentroidFilter::push(FeatureList& features, FilterContext& context )
{
    for( FeatureList::iterator i = features.begin(); i != features.end(); ++i )
    {
        Feature* f = i->get();
        
        Geometry* geom = f->getGeometry();
        if ( !geom )
            continue;

        PointSet* newGeom = new PointSet();
        newGeom->push_back( geom->getBounds().center() );

        f->setGeometry( newGeom );
    }

    return context;
}
