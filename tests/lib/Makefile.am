SUBDIRS = trace-ir ctf-writer

AM_CPPFLAGS += -I$(top_srcdir)/tests/utils

LIBTAP=$(top_builddir)/tests/utils/tap/libtap.la

libtestcommon_la_SOURCES = common.c common.h
noinst_LTLIBRARIES = libtestcommon.la

# -Wl,--no-as-needed is needed for recent gold linker who seems to think
# it knows better and considers libraries with constructors having
# side-effects as dead code.
COMMON_TEST_LDADD = $(LIBTAP) $(builddir)/libtestcommon.la \
	$(top_builddir)/lib/libbabeltrace.la

test_bitfield_LDADD = $(LIBTAP) $(builddir)/libtestcommon.la

test_ctf_writer_LDADD = $(COMMON_TEST_LDADD)

test_bt_values_LDADD = $(COMMON_TEST_LDADD)

test_trace_ir_ref_LDADD = $(COMMON_TEST_LDADD)

test_graph_topo_LDADD = $(COMMON_TEST_LDADD)

noinst_PROGRAMS = test_bitfield test_ctf_writer test_bt_values \
	test_trace_ir_ref test_graph_topo

test_bitfield_SOURCES = test_bitfield.c
test_ctf_writer_SOURCES = test_ctf_writer.c
test_bt_values_SOURCES = test_bt_values.c
test_trace_ir_ref_SOURCES = test_trace_ir_ref.c
test_graph_topo_SOURCES = test_graph_topo.c

check_SCRIPTS = test_ctf_writer_complete

if !ENABLE_BUILT_IN_PLUGINS
noinst_PROGRAMS += test_plugin
test_plugin_LDADD = $(COMMON_TEST_LDADD)
test_plugin_SOURCES = test_plugin.c
check_SCRIPTS += test_plugin_complete
SUBDIRS += test-plugin-plugins
endif
