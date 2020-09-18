#!/bin/bash

set -Eeou pipefail

# TODO separate build dirs for different architectures
cd "${ROOT}"
./configure CFLAGS='-D__UBPORTS__' CXXFLAGS='-D__UBPORTS__' --prefix="/" --host="${ARCH_TRIPLET}" --binary-dir="lib/${ARCH_TRIPLET}/bin" --install-dir="${INSTALL_DIR}"
make -j4
make DESTDIR="${INSTALL_DIR}" install
