/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <fabric/core/LocalData.h>
#include <fabric/graphics/Geometry.h>

namespace facebook {
namespace react {

class ScrollViewLocalData;

using SharedScrollViewLocalData = std::shared_ptr<const ScrollViewLocalData>;

/*
 * LocalData for <ScrollView> component.
 */
class ScrollViewLocalData:
  public LocalData {

public:
  ScrollViewLocalData(Rect contentBoundingRect);

  /*
   * Compound size of all nested (first level only) components;
   * is used for computing `contentSize`.
   */
  const Rect contentBoundingRect;

#pragma mark - Getters

  Size getContentSize() const;

#pragma mark - DebugStringConvertible

#if RN_DEBUG_STRING_CONVERTIBLE
  std::string getDebugName() const override;
  SharedDebugStringConvertibleList getDebugProps() const override;
#endif
};

} // namespace react
} // namespace facebook
