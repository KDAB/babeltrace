AM_CPPFLAGS += -I$(top_srcdir)/plugins

libbabeltrace_plugin_ctf_lttng_live_la_SOURCES = \
		lttng-live.c \
		lttng-live.h \
		data-stream.c \
		data-stream.h \
		metadata.c \
		metadata.h \
		viewer-connection.c \
		viewer-connection.h \
		lttng-viewer-abi.h \
		logging.c \
		logging.h

if BABELTRACE_BUILD_WITH_MINGW
libbabeltrace_plugin_ctf_lttng_live_la_LIBADD = -lws2_32
endif

noinst_LTLIBRARIES = libbabeltrace-plugin-ctf-lttng-live.la
