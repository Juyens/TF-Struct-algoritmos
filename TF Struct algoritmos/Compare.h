#pragma once

#include <functional>

// Generic comparator wrapper. Defaults to std::less for the provided type.
// This mirrors the behavior expected by BSTree but keeps the header optional.

template <typename T>
struct Compare : std::less<T> {};

