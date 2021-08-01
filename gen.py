from re import *

# Generate vec3f.cpp from vec4f.cpp
vec4f_file = open('vec4f.cpp', 'r')
vec4f_lines = vec4f_file.readlines()
vec4f_file.close()

vec3f_file = open('vec3f.cpp', 'w')
vec3f_lines = []

for i, line in enumerate(vec4f_lines):

    # Exclude lines with Vec3f
    if not search('Vec3f', line) or search('^//', line):
        # Rename constructors and calls
        line = sub('Vec4f', 'Vec3f', line)

        # Replace x,x,x,x with x,x,x
        line = sub(r'(.*), \1, \1, \1', r'\1, \1, \1', line)

        # Replace x y z w with x y z
        line = sub(r'(x(.*)y\2z)\2w', r'\1', line)

        # Replace xx yy zz ww with xx yy zz
        line = sub(r'(x(.*)x([\S\s]*)y\2y\3z\2z)\3w\2w', r'\1', line)

        # Include lines that are explicitly meant for this file
        line = sub(r'//vec3f\.cpp: (.*)', r'\1', line)

        # Exclude lines with Vec3f(x, x, x, x)
        if not search(r'Vec3f\([^,)]*,[^,)]*,[^,)]*,[^,)]*\)', line):
            vec3f_lines.append(line)

vec3f_text = ''.join(vec3f_lines)

# Replace x y z w with x y z, multiline
vec3f_text = sub(r'(x([\S\s]*)y\2z)\2w', r'\1', vec3f_text)

# Replace xx yy zz ww with xx yy zz, multiline
vec3f_text = sub(r'(x([\S\s]*)x([\S\s]*)y\2y\3z\2z)\3w\2w', r'\1', vec3f_text)

# Write to vec3f.cpp
vec3f_file.write(vec3f_text)
vec3f_file.close()

# Generate vec2f.cpp from vec3f.cpp
vec3f_lines = vec3f_text.split('\n')

vec2f_file = open('vec2f.cpp', 'w')
vec2f_lines = []

for i, line in enumerate(vec3f_lines):

    # Exclude lines with Vec2f
    if not search('Vec2f', line) or search('^//', line):
        # Rename constructors and calls
        line = sub('Vec3f', 'Vec2f', line)

        # Replace x,x,x with x,x
        line = sub(r'(.*), \1, \1', r'\1, \1', line)

        # Replace x y z with x y
        line = sub(r'(x(.*)y)\2z', r'\1', line)

        # Replace xx yy zz with xx yy
        line = sub(r'(x(.*)x([\S\s]*)y\2y)\3z\2z', r'\1', line)

        # Include lines that are explicitly meant for this file
        line = sub(r'//vec2f\.cpp: (.*)', r'\1', line)

        # Exclude lines with Vec2f(x, x, x)
        if not search(r'Vec2f\([^,)]*,[^,)]*,[^,)]*\)', line):
            vec2f_lines.append(line)

vec2f_text = '\n'.join(vec2f_lines)

# Replace x y z with x y, multiline
vec2f_text = sub(r'(x([\S\s]*)y)\2z', r'\1', vec2f_text)

# Replace xx yy zz ww with xx yy zz, multiline
vec2f_text = sub(r'(x([\S\s]*)x([\S\s]*)y\2y)\3z\2z', r'\1', vec2f_text)

# Write to vec2f.cpp
vec2f_file.write(vec2f_text)
vec2f_file.close()
