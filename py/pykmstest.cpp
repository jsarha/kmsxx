#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <kms++.h>
#include "kmstest.h"

namespace py = pybind11;

using namespace kms;
using namespace std;

void init_pykmstest(py::module &m)
{
	py::class_<RGB>(m, "RGB")
			.def(py::init<>())
			.def(py::init<uint8_t, uint8_t, uint8_t&>())
			.def(py::init<uint8_t, uint8_t, uint8_t, uint8_t&>())
			;

	// Use lambdas to handle IMappedFramebuffer
	m.def("draw_test_pattern", [](DumbFramebuffer& fb) { draw_test_pattern(fb); } );
	m.def("draw_color_bar", [](DumbFramebuffer& fb, int old_xpos, int xpos, int width) {
		draw_color_bar(fb, old_xpos, xpos, width);
	} );
	m.def("draw_rect", [](DumbFramebuffer& fb, uint32_t x, uint32_t y, uint32_t w, uint32_t h, RGB color) {
		draw_rect(fb, x, y, w, h, color);
	} );
}