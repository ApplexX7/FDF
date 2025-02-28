FROM alpine:3.21.2

# Install the necessary build dependencies
RUN apk add --no-cache \
    musl-dev \
    git \
    gcc \
    make \
    xorg-server \
    libxext-dev \
    libbsd-dev \
    g++ \
    mesa-dev \
    mesa-dri-gallium \
    bash \
    libx11 \
    libxrender \
    libxtst \
    libxft \
    fontconfig

WORKDIR /home/app

# Clone the repo
RUN git clone --recurse-submodules https://github.com/ApplexX7/FDF.git

WORKDIR /home/app/FDF

# Disable AddressSanitizer (optional, remove if you need it)
ENV CFLAGS="-fno-omit-frame-pointer -g"
ENV LDFLAGS="-no-pie"

# Build the project
RUN make all

CMD ["sh", "-c", "./FDF maps/42.fdf; exec sh"]
