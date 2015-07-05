#!/bin/sh
CURRENT_DIR=$(dirname $0)
export LD_LIBRARY_PATH="${CURRENT_DIR}/lib":$LD_LIBRARY_PATH

$CURRENT_DIR/azriel_sl_ax_main_main
