#!/usr/bin/env bash
#
# Convert a directory of pngs to web video(s)


if [ -z "$WIRESHARK_APP_DIR" ] ; then
	WIRESHARK_APP_DIR="/Applications/Wireshark.app"
fi

if [ ! -d "$WIRESHARK_APP_DIR" ] ; then
	echo "Wireshark doesn't appear to be located at $WIRESHARK_APP_DIR."
	echo "Please set WIRESHARK_APP_DIR to its proper location and try again."
	exit 1
fi

APPNAME=`basename "$0"`
exec "$WIRESHARK_APP_DIR/Contents/Resources/bin/$APPNAME" "$@"

