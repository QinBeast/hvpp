#pragma once
#include "ia32/memory.h"
#include "ia32/mtrr.h"

namespace memory_manager
{
  namespace detail
  {
    void* system_allocate(size_t size) noexcept;
    void system_free(void* address) noexcept;
  }

  void initialize() noexcept;
  void destroy() noexcept;
  void assign(void* address, size_t size) noexcept;

  void* allocate(size_t size) noexcept;
  void free(void* address) noexcept;

  size_t allocated_bytes() noexcept;
  size_t free_bytes() noexcept;

  const ia32::physical_memory_descriptor& physical_memory_descriptor() noexcept;
  const ia32::mtrr& mtrr() noexcept;

  inline void* system_allocate(size_t size) noexcept
  { return detail::system_allocate(size); }

  inline void system_free(void* address) noexcept
  { detail::system_free(address); }
}
