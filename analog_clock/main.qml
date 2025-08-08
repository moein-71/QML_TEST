import QtQuick 2.15
import QtQuick.Window 2.15

Window {
    visible: true
    width: 400
    height: 400
    title: "Analog Clock with Numbers"

    Rectangle {
        anchors.fill: parent
        color: "#333"

        Canvas {
            id: clock 
            anchors.centerIn: parent
            width: 300
            height: 300
            onPaint: {
                var ctx = getContext("2d");
                ctx.reset();
                var centerX = width / 2;
                var centerY = height / 2;
                var radius = Math.min(width, height) / 2 - 10;

                // پس‌زمینه دایره‌ای
                ctx.fillStyle = "#222";
                ctx.beginPath();
                ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI);
                ctx.fill();

                // رسم اعداد ساعت
                ctx.fillStyle = "#fff";
                ctx.font = "16px sans-serif";
                ctx.textAlign = "center";
                ctx.textBaseline = "middle";
                for (var i = 1; i <= 12; i++) {
                    var angle = (i - 3) * (Math.PI * 2) / 12;
                    var x = centerX + Math.cos(angle) * (radius - 25);
                    var y = centerY + Math.sin(angle) * (radius - 25);
                    ctx.fillText(i.toString(), x, y);
                }

                // گرفتن زمان فعلی
                var now = new Date();
                var hour = now.getHours() % 12;
                var minute = now.getMinutes();
                var second = now.getSeconds();

                // عقربه ساعت
                var hourAngle = ((hour + minute / 60) * 30) * Math.PI / 180;
                drawHand(ctx, centerX, centerY, hourAngle, radius * 0.5, 6, "#fff");

                // عقربه دقیقه
                var minuteAngle = ((minute + second / 60) * 6) * Math.PI / 180;
                drawHand(ctx, centerX, centerY, minuteAngle, radius * 0.8, 4, "#aaa");

                // عقربه ثانیه
                var secondAngle = (second * 6) * Math.PI / 180;
                drawHand(ctx, centerX, centerY, secondAngle, radius * 0.9, 2, "red");

                // نقطه وسط
                ctx.fillStyle = "white";
                ctx.beginPath();
                ctx.arc(centerX, centerY, 5, 0, 2 * Math.PI);
                ctx.fill();
            }

            function drawHand(ctx, x, y, angle, length, width, color) {
                ctx.save();
                ctx.translate(x, y);
                ctx.rotate(angle);
                ctx.beginPath();
                ctx.moveTo(0, 0);
                ctx.lineTo(0, -length);
                ctx.lineWidth = width;
                ctx.strokeStyle = color;
                ctx.stroke();
                ctx.restore();
            }

            Timer {
                interval: 1000
                running: true
                repeat: true
                onTriggered: clock.requestPaint()
            }
        }
    }
}
