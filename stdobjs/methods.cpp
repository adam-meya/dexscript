/*   DexScript scripting language, a value-based scripting language.
 *   Mutation must be made explicit. The language makes heavy use of
 *   copy-on-write techniques.
 *
 *   Copyright (C) 2012 Adam Domurad
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <http://www.gnu.org/licenses/>.*/

#include "methods.h"
#include "../mainh.h"
#include "../interp/error.h"
#include "../parsing/op.h"

const char NOARGS[] = "Expected no arguments.";
const char ONEARGS[] = "Expected 1 argument.";
const char TWOARGS[] = "Expected 2 arguments.";

void dm_objstr(DexRef& self, DexRef* args, size_t n) {
	if (n != 0) {
		arg_amnt_err("str", n, 0, self->type);
		self = NONE;
	} else
		self = dex_to_string(self);
}

void dm_objconcat(DexRef& self, DexRef* args, size_t n) {
	if (n != 1){
		arg_amnt_err("concat", n, 1, self->type);
		self = NONE;
	} else
	dex_operation(opCAT, self, *args);
}

void dm_objhash(DexRef& self, DexRef* args, size_t n) {
	if (n != 1){
		arg_amnt_err("hash", n, 1, self->type);
		self = NONE;
	} else
	self = dex_hash(self);
}

void dm_objreinit(DexRef& self, DexRef* args, size_t n) {
	self = create_dex_object(self->type, args, n);
}
