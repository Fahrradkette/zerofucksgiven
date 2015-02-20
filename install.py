#!/bin/python

# compiles and deploys "zerofucksgiven" to "/home/user/bin"
# creating subdirectory "bin" if neccesary

from os import path, environ, mkdir
from subprocess import check_output, CalledProcessError

def install(installdir):
    binaries = ["fuck", "fucksgiven", "forgiveme"]
    for binary in binaries:
        try:
            retval = check_output(["gcc",
                                   binary + ".c",
                                   "-o",
                                   installdir + "/" + binary])
            if len(retval):
                print "error occured while compiling {}.c :{}".format(binary, retval)
            else:
                print "compiling {} passed without error, it's put to {}".format(binary, installdir)
        except CalledProcessError as e:
            print "Coudn't call gcc properly, here is the error: {}".format(e)

homedir = "HOME" in environ
if homedir:
    homedir = environ["HOME"]
    bindir = homedir + "/bin"
    if homedir and path.exists(bindir):
        print "{} exists".format(bindir)
    else:
        print "bin directory didn't exist yet, creating it..."
        try:
            mkdir(bindir)
            print "{} created".format(bindir)
        except OSError:
            print "coudn't create {} because it may already existed".format(bindir)
    try:    
        gcc_package = check_output(["dpkg", "--get-selections", "build-essential"])
        if gcc_package.count(chr(9) + "install") or gcc_package.count(chr(32) + "install"):
            print "compiler should be persent, I'll try to compile..."
            install(bindir)
        else:
            print "coudn't find the building packet, try:"
            print "sudo apt-get update"
            print "sudo apt-get install build-essential"
    except CalledProcessError as e:
        print "something went wrong while calling dpkg, here is the error: {}".format(e)

print
print "if no error occured, log in again and type 'fucksgiven' to try it out"
print "Note that may only work on a Debian system. You might have to add {}".format(bindir)
print "to your $PATH in something like ~/.bash_profile or ~/.bashrc"
