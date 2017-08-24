MRuby::Build.new do |conf|

  # Gets set by the VS command prompts.
  if ENV['VisualStudioVersion'] || ENV['VSINSTALLDIR']
    toolchain :visualcpp
  else
    toolchain :gcc
  end

  enable_debug

  # include the default GEMs
  conf.gembox 'default'

end

MRuby::CrossBuild.new('kernel') do |conf|
  toolchain :gcc

  conf.cc do |cc|
    cc.include_paths << %w(include/kernel)
    cc.flags << "-mcmodel=kernel -nostdinc -nostdlib -fno-builtin -fno-PIE -mno-red-zone -fno-asynchronous-unwind-tables -fno-omit-frame-pointer -fno-stack-protector"
    cc.defines << %w(DISABLE_STDIO)
    cc.defines << %w(MRB_WITHOUT_FLOAT)
  end

  conf.cxx do |cxx|
    cxx.command = conf.cc.command.dup
    cxx.include_paths = conf.cc.include_paths.dup
    cxx.flags = conf.cc.flags.dup
    cxx.defines = conf.cc.defines.dup
    cxx.compile_options = conf.cc.compile_options.dup
  end

  #no executables
  conf.bins = []

  #do not build executable test
  conf.build_mrbtest_lib_only

  #disable C++ exception
  conf.disable_cxx_exception
end
