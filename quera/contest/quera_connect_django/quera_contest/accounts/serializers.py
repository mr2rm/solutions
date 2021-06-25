from rest_framework import serializers

from .models import User


class UserSerializer(serializers.ModelSerializer):
    password = serializers.CharField(write_only=True)

    class Meta:
        model = User
        fields = (
            'username',
            'password',
            'full_name',
            'phone',
            'address',
            'gender',
            'age',
            'description',
            'email',
        )

    def create(self, validated_data):
        user = User.objects.create_user(**validated_data)
        return user
