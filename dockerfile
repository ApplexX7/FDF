FROM alpine:3.21.2
RUN  apk add musl-dev git gcc make xorg-server libxext-dev libbsd-dev

WORKDIR /home/app

RUN git clone --recurse-submodules https://github.com/ApplexX7/FDF.git

WORKDIR /home/app/FDF

RUN make all

CMD ["sh", "-c", "./FDF maps/42.fdf; exec sh"]