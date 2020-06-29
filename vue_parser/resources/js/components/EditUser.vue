<template>
  <div>
    <h1>Edit User</h1>
    <form @submit.prevent="updateUser">
      <div class="row justify-content-center">
        <div class="col-md-6">
          <div class="form-group">
            <label>Steam username:</label>
            <input type="text" class="form-control" v-model="steamuser.username">
            <label>Steam ID</label>
            <input type="text" class="form-control" v-model="steamuser.steam_id">
          </div>
        </div>
        </div>
        <div class="form-group">
          <button class="btn btn-primary">Update</button>
        </div>
    </form>
  </div>
</template>

<script>
export default {
    data(){
        return {
            steamuser: {}
        }
    },
    created() {
        let uri = `/api/steamuser/edit/${this.$route.params.id}`;
        this.axios.get(uri).then((response) => {
            this.steamuser = response.data;
        })
    },

    methods: {
        updateUser(){
            let uri = `/api/steamuser/update/${this.$route.params.id}`;
            this.axios.post(uri, this.steamuser).then((response) => {
                this.$router.push({name: 'userspage'});
            });
        }
    }
}
</script>