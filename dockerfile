FROM ubuntu:20.04

RUN apt-get update --fix-missing && apt-get upgrade -y

RUN  apt -y  install libx11-dev \
    libxext-dev \
    libxrender-dev \
    build-essential \
    libbsd-dev

WORKDIR /Fdf

COPY . /Fdf/

RUN make all

CMD ["./FDF", "./map/42.fdf"]