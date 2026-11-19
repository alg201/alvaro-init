mkdir -pv kernels

sudo cp -v /boot/vmlinuz-$(uname -r) kernels/vmlinuz
sudo chown -v "$USER":"$(id -gn)" kernels/vmlinuz