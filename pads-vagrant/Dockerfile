FROM ubuntu:18.04

RUN dpkg --add-architecture i386
RUN apt-get update && apt-get upgrade -y && apt-get autoremove

RUN apt-get install -y apt-utils git build-essential

RUN apt-get install -y bison flex

#for use to build SML/NJ on Ubuntu 16.04:
RUN apt-get install -y wget
RUN apt-get install -y libc6:i386
RUN apt-get install -y gcc-multilib g++-multilib
RUN apt-get install -y libstdc++6:i386 libgcc1:i386 zlib1g:i386 libncurses5:i386 lib32z1

ENV smldir /usr/share/smlnj
ENV v 110.83
RUN mkdir $smldir && cd $smldir \
    && wget http://smlnj.cs.uchicago.edu/dist/working/$v/config.tgz \
    && tar -xzf config.tgz && config/install.sh
#ENV SML $smldir/bin/sml
ENV PATH $smldir/bin:$PATH

RUN cd && git clone https://github.com/packerliu/pads.git
ENV PADS_HOME /root/pads
RUN . $PADS_HOME/scripts/Q_DO_SETENV.sh

RUN cd $PADS_HOME && make && make regress
# Step 2: SML/NJ is based on 110.83 from https://www.smlnj.org/, 
#    - Somehow, ubuntu package SML/NJ on 18.04LTS does not contain ml-ulex, ml-yacc.
#      Maybe a wrong package? https://launchpad.net/ubuntu/bionic/i386/smlnj/110.79-4
#    - Buils i386 arch for SML/NJ since it is based on 32bit. Look at: 
#      https://wiki.debian.org/Multiarch/HOWTO
# Step 3: possible look at libast if it keep failing to build: 
#    - https://github.com/att/ast/tree/master/src/lib/libast 
