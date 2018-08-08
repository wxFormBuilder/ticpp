project('ticpp', 'cpp', default_options : ['cpp_std=c++17'])

add_project_arguments('-DTIXML_USE_TICPP', language : 'cpp')

ticpp_dep = declare_dependency(include_directories : include_directories('.'),
	link_with : static_library('ticpp', [
			'ticpp.cpp',
			'tinystr.cpp',
			'tinyxml.cpp',
			'tinyxmlerror.cpp',
			'tinyxmlparser.cpp',
		]))
