// landmarks.h: code for manipulating landmarks
//
// Copyright (C) 2005-2013, Stephen Milborrow

#ifndef STASM_LANDMARKS_H
#define STASM_LANDMARKS_H

namespace stasm
{
struct LANDMARK_INFO  // landmark information
{
    int   partner;    // symmetrical partner point, -1 means no partner

    int   prev, next; // previous and next point
                      // special val -1 means prev=current-1 and next=current+1
                      // see Milborrow master's thesis Section 5.4.8 "Whisker Directions"

    double weight;    // weight of landmark relative to others (for shape mod)

    unsigned bits;    // used only during training (AT_Glasses, etc.)
};

#include "/Users/Zeming/Desktop/stasm4.1.0/tasm/landtab/landtab_helen194.h" // changed for Helen 194 dataset

double MeanPoint(
    const Shape& shape,       // in
    int          ipoint1,     // in
    int          ipoint2,     // in
    int          ix);         // in: IX or IY

void PrevAndNextLandmarks(
    int&         prev,        // out
    int&         next,        // out
    int          ipoint,      // in
    const Shape& shape);      // in

Shape FlipShape(              // flip shape horizontally
    const Shape& shape,       // in
    int          imgwidth);   // in

} // namespace stasm
#endif // STASM_LANDMARKS_H
