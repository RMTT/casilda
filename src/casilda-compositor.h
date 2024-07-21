/*
 * Casilda Wayland Compositor Widget
 *
 * Copyright (C) 2024  Juan Pablo Ugarte
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation;
 * version 2.1 of the License.
 *
 * library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 * Authors:
 *   Juan Pablo Ugarte <juanpablougarte@gmail.com>
 */

#pragma once

#include <gtk/gtk.h>

#define CASILDA_COMPOSITOR_TYPE (casilda_compositor_get_type ())
G_DECLARE_FINAL_TYPE (CasildaCompositor, casilda_compositor, CASILDA, COMPOSITOR, GtkDrawingArea)

CasildaCompositor *casilda_compositor_new (const gchar * socket);
void           casilda_compositor_cleanup (CasildaCompositor *object);
void           casilda_compositor_set_bg_color (CasildaCompositor *compositor,
                                                gdouble            red,
                                                gdouble            green,
                                                gdouble            blue);
void           casilda_compositor_forget_toplevel_state (CasildaCompositor *compositor);
