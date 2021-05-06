
#pragma once

// Make "signals:", "slots:" visible as access specifiers
#define QT_ANNOTATE_ACCESS_SPECIFIER(a) __attribute__((annotate(#a)))

#include <qgsinterval.h>
#include <qgsfield.h>
#include <qgsfeature.h>
#include <qgsfeedback.h>
#include <qgsgeometry.h>
#include <qgsvectorlayer.h>
#include <qgsmaplayer.h>
#include <qgsmaplayerrenderer.h>
#include <qgsrendercontext.h>
#include <qgscoordinatetransformcontext.h>
#include <qgsreadwritecontext.h>
#include <qgsunittypes.h>
#include <qgswkbtypes.h>
